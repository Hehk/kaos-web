open Utils;

type style =
  | Outline
  | Full
  | Simple;

let component = ReasonReact.statelessComponent("Button");

let getClassName = (style) =>
  switch style {
  | Outline => "f6 fw4 b--solid bw1 b--light-purple no-underline light-purple dn\n  dib-ns pv2 ph3 br1 hover-white hover-bg-light-purple ma2"
  | Full => ""
  | Simple => "f6 fw4 hover-purple no-underline black dn dib-ns pv2 ph3"
  };

let make = (~style=Simple, ~className="", children) => {
  ...component,
  render: (_self) =>
    <div className=(getClassName(style) ++ " " ++ className)> (arrayEl(children)) </div>
};
