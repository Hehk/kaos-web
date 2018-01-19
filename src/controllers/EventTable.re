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

let reduceOpenEdit = (~listIndex, ~eventIndex, state) => {...state, edit: {active: true, listIndex, eventIndex}};

let reduceCloseEdit = (state) => {...state, edit: {active: false, listIndex: (-1), eventIndex: (-1)}};
let reduceAddEvent = (~listIndex, ~event:Event.t, state) => { 
  ...state,
  eventLists: List.mapi((i, eventList: EventList.t)=> {
    if (i == listIndex) {
      { ...eventList, events: eventList.events @ [event] };
    } else {
      eventList
    };
  }, state.eventLists)
};

type action =
  | MoveEvent
  | OpenEdit(int, int)
  | CloseEdit
  | AddEvent(int, Event.t);

let reducer = (action, state) =>
  switch action {
  | MoveEvent => ReasonReact.Update(state)
  | OpenEdit(listIndex, eventIndex) => ReasonReact.Update(state |> reduceOpenEdit(~listIndex, ~eventIndex))
  | CloseEdit => ReasonReact.Update(state |> reduceCloseEdit)
  | AddEvent(listIndex, event) => ReasonReact.Update(state |> reduceAddEvent(~listIndex, ~event))
  };

let component = ReasonReact.reducerComponent("EventTable");

let make = (_) => {
  ...component,
  initialState,
  reducer,
  render: (self) =>
    <div className="dt w-100 mw8 center flex flex-wrap justify-center">
      (self.state.edit.active ? textEl("active") : textEl("inactive"))
      (self.state.eventLists |> List.mapi((listIndex, {name, events}: EventList.t) =>
        <EventList
          name
          events
          onEventClick=(eventIndex => self.send(OpenEdit(listIndex, eventIndex)))
          onAddEvent=((event) => self.send(AddEvent(listIndex, event)))
          key=name
        />) |> listEl)
    </div>
};
