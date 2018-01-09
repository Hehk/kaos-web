open Utils;

type style =
  | InheritStyle
  | Simple;

let component = ReasonReact.statelessComponent("Link");

let make = {
  let inheritStyleLink  = (~children, ~href) => <a className="color-inherit link" href> (arrayEl(children)) </a>;
  let simpleLink = (~children, ~href) => <a href> (arrayEl(children)) </a>;

  (~style=Simple, ~href, children) => {
    ...component,
    render: (_self) =>
      switch style {
      | Simple => simpleLink(~children, ~href)
      | InheritStyle => inheritStyleLink(~children, ~href)
      }
  }
};
