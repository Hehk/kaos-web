open Utils;

type state = {
  columns: list(EventList.t)
};

type action =
| MoveEvent;

let component = ReasonReact.reducerComponent("EventTable");

let initialState = () => {
  columns: [{
    name: "testing",
    events: [{
      name: "event-1"
    }, {
      name: "event-2"
    }]
  }]
};

let reducer = (action, state) =>
  switch (action) {
  | MoveEvent => ReasonReact.Update(state)
  };

let make = (_) => {
  ...component,
  initialState,
  reducer,
  render: ({ state }) => <div className="dt w-100 mw8 center">
      (state.columns |> List.map(({ name, events }: EventList.t) => <EventList name events key=name />) |> listEl)
    </div>
}
