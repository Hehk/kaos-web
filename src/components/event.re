open Utils;

type t = {
  name: string
};

let component = ReasonReact.statelessComponent("Event");

let make = (~name, _children) => {
  ...component,
  render: (_self) => <div className="light-purple pa3 mt3 br1 bg-light-purple hover-white">
    <span className="white">(textEl(name))</span> <span

  className="fr fa fa-ellipsis-h"></span> </div>
};
