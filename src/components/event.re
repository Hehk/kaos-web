open Utils;

type t = {
  name: string
};

let component = ReasonReact.statelessComponent("Event");

let make = (~name, _children) => {
  ...component,
  render: (_self) => <div className="ma2 shadow-3 br1 bg-light-purple"> (textEl(name)) </div>
};
