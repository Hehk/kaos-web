open Utils;

type state = {eventLists: list(EventList.t)};

type action =
  | MoveEvent;

let component = ReasonReact.reducerComponent("EventTable");

let initialState = () => {
  eventLists: [
    {name: "Morning", events: [{name: "event-1"}, {name: "event-2"}]},
    {name: "Afternoon", events: [{name: "event-1"}, {name: "event-2"}]},
    {name: "Evening", events: [{name: "event-1"}, {name: "event-2"}]}
  ]
};

let reducer = (action, state) =>
  switch action {
  | MoveEvent => ReasonReact.Update(state)
  };

let make = (_) => {
  ...component,
  initialState,
  reducer,
  render: ({state}) =>
    <div className="dt w-100 mw8 center flex flex-wrap justify-center">
      (state.eventLists |> List.map(({name, events}: EventList.t) => <EventList name events key=name />) |> listEl)
    </div>
};
