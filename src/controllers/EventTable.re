open Utils;

type editFrame = {
  active: bool,
  listIndex: int,
  eventIndex: int
};

type state = {
  eventLists: list(EventList.t),
  edit: editFrame
};

let initialState = () => {
  eventLists: [
    {name: "Morning", events: [{name: "event-1"}, {name: "event-2"}]},
    {name: "Afternoon", events: [{name: "event-1"}, {name: "event-2"}]},
    {name: "Evening", events: [{name: "event-1"}, {name: "event-2"}]}
  ],
  edit: {active: false, listIndex: (-1), eventIndex: (-1)}
};

let resolveOpenEdit = (listIndex, eventIndex, state) => {...state, edit: {active: true, listIndex, eventIndex}};

let resolveCloseEdit = (state) => {...state, edit: {active: false, listIndex: (-1), eventIndex: (-1)}};

type action =
  | MoveEvent
  | OpenEdit(int, int)
  | CloseEdit;

let reducer = (action, state) =>
  switch action {
  | MoveEvent => ReasonReact.Update(state)
  | OpenEdit(listIndex, eventIndex) => ReasonReact.Update(resolveOpenEdit(listIndex, eventIndex, state))
  | CloseEdit => ReasonReact.Update(resolveCloseEdit(state))
  };

let component = ReasonReact.reducerComponent("EventTable");

let make = (_) => {
  ...component,
  initialState,
  reducer,
  render: ({state}) =>
    <div className="dt w-100 mw8 center flex flex-wrap justify-center">
      (state.eventLists |> List.map(({name, events}: EventList.t) => <EventList name events key=name />) |> listEl)
    </div>
};
