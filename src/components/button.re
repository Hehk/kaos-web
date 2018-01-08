open Utils;

type style =
  | Outline
  | Full
  | Simple;

let component = ReasonReact.statelessComponent("Button");

let make = {
  let outlineButton = (children) =>
    <div
      className="f6 fw4 b--solid bw1 b--light-purple no-underline light-purple dn\n  dib-ns pv2 ph3 br1 hover-white hover-bg-light-purple ma2">
      (arrayEl(children))
    </div>;
  let fullButton = (children) => <div> (arrayEl(children)) </div>;
  let simpleButton = (children) =>
    <div className="f6 fw4 hover-purple no-underline black dn dib-ns pv2 ph3">
      (arrayEl(children))
    </div>;
  (~style, children) => {
    ...component,
    render: (_self) =>
      switch style {
      | Outline => outlineButton(children)
      | Full => fullButton(children)
      | Simple => simpleButton(children)
      }
  }
};
