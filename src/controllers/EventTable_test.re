open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let shallow = Enzyme.shallow;

describe(
  "EventTable Component",
  () => test("Component renders", () => shallow(<EventTable />) |> Enzyme.exists |> expect |> toBe(true))
);

describe(
  "EventTable Reducer",
  () =>
    test(
      "MoveEvent",
      () => {
        let state: EventTable.state = EventTable.initialState();
        switch (EventTable.reducer(EventTable.MoveEvent, state)) {
        | ReasonReact.Update(newState) => newState |> expect |> toEqual(state)
        | _ => false |> expect |> toBe(true)
        }
      }
    )
);

describe(
  "reduceOpenEdit",
  () =>
    test(
      "basic call",
      () => {
        let state: EventTable.state = EventTable.initialState();
        EventTable.reduceOpenEdit(~listIndex=1, ~eventIndex=2, state)
        |> expect
        |> toEqual({...state, edit: {active: true, listIndex: 1, eventIndex: 2}})
      }
    )
);

describe(
  "reduceCloseEdit",
  () =>
    test(
      "basic call",
      () => {
        let state: EventTable.state = {
          ...EventTable.initialState(),
          edit: {active: true, listIndex: 5, eventIndex: 6}
        };
        state
        |> EventTable.reduceCloseEdit
        |> expect
        |> toEqual({...state, edit: {active: false, listIndex: (-1), eventIndex: (-1)}})
      }
    )
);

describe("reduceAddEvent", () => test("basic call", () => {
  let state = EventTable.initialState();
  let event: Event.t = { name: "new event" };
  let initialState = {
    ...state,
    eventLists: [
      {name: "test", events: [] }
    ]
  };
  let finalState = {
    ...state,
    eventLists: [
    { name: "test", events: [event] }
    ]
  };
  initialState |> EventTable.reduceAddEvent(~listIndex=0, ~event) |> expect |> toEqual(finalState);
}));
