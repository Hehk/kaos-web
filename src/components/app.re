open Utils;

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: (_self) =>
    <div className="App">
      <div className="App-header">
        <h2> (textEl(message)) </h2>
      </div>
      <p className="App-intro">
        (textEl("To get started, edit"))
        <code> (ReasonReact.stringToElement(" src/app.re ")) </code>
        (textEl("and save to reload."))
      </p>
    </div>
};
