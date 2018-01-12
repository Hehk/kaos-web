open Utils;

type t = {
  name: string,
  events: list(Event.t)
};

let component = ReasonReact.statelessComponent("EventList");

let make = (~name, _children) => {
  ...component,
  render: _self => {
    <div>(textEl(name))</div>
  }
};

