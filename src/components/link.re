open Utils;

type style =
  | InheritStyle
  | Simple;

let component = ReasonReact.statelessComponent("Link");

let handleClick = (href, event) =>
  if (! ReactEventRe.Mouse.defaultPrevented(event)) {
    ReactEventRe.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };

let getClassName = style =>
  switch style {
  | Simple => ""
  | InheritStyle => "color-inherit link"
  };

let make = (~style=Simple, ~href, ~className="", children) => {
  ...component,
  render: _self =>
    <a
      className=(getClassName(style) ++ " " ++ className)
      href
      onClick=(handleClick(href))>
      (arrayEl(children))
    </a>
};
