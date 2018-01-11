open Utils;

type t = {
  name: string
};

let component = ReasonReact.statelessComponent("Event");

let make = (~name, _children) => {
  ...component,
  render: (_self) => <div> (textEl(name)) </div>
};
