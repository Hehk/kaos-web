open Utils;

type t = {
  name: string,
  events: list(Event.t)
};

let component = ReasonReact.statelessComponent("EventList");

let make = (~name, ~events: list(Event.t)=[], _children) => {
  ...component,
  render: _self => {
    <div className="w-100 mw6 w-30-l pa2">
      <div className="f3"> (textEl(name)) </div>
      <div>
      (
        events
        |> List.map((event: Event.t)=> <Event key=(name ++ event.name) name=event.name />)
        |> listEl
      )
      </div>
    </div>
  }
};

