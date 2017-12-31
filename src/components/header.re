open Utils;

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div id="header">
      (textEl("Hello World"))
    </div>
};
