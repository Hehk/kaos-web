open Utils;

type t = {
  name: string
};

let component = ReasonReact.statelessComponent("Event");

let make = (~name, _children) => {
  ...component,
  render: (_self) => <div className="white pa2 mt2 br1 bg-light-purple"> (textEl(name)) </div>
};
