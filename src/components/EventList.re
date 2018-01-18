open Utils;

type t = {
  name: string,
  events: list(Event.t)
};

let component = ReasonReact.statelessComponent("EventList");

let createEvent = (listener, _event) => {
  let event: Event.t = {
    name: "new event"
    };
  listener(event)
};
let make = (~name, ~events: list(Event.t)=[], ~onAddEvent, _children) => {
  ...component,
  render: _self => {
    <div className="w-100 mw6 w-30-l pa2 ">
      <div className="f3 b dark-gray"> (textEl(name)) </div>
      (
        events
        |> List.map((event: Event.t)=> <Event key=(name ++ event.name) onClick=(() => Js.log("test")) name=event.name />)
        |> listEl
      )
      <div className="add-new-event pa3 gray" onClick=createEvent(onAddEvent)> (textEl("Add new event")) </div>
    </div>
  }
};

