let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div id="header">
      (ReasonReact.stringToElement("Hello World"))
    </div>
};
