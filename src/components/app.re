open Utils;

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: (_self) =>
    <div className="App">
      <Header />
      <div className="App-header">
        <h2> (textEl(message)) </h2>
      </div>
      <p className="App-intro">
        (textEl("To get started, edit"))
        <code> (textEl(" src/app.re ")) </code>
        (textEl("and save to reload."))
      </p>
    </div>
};
