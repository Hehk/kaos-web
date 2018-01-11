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
    events: []
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
  render: ({ state }) => <div>
      (state.columns |> List.map(({ name }: EventList.t) => <EventList name key=name />) |> listEl)
    </div>
}
