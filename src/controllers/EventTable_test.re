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
  "resolveOpenEdit",
  () =>
    test(
      "basic call",
      () => {
        let state: EventTable.state = EventTable.initialState();
        EventTable.resolveOpenEdit(1, 2, state)
        |> expect
        |> toEqual({...state, edit: {active: true, listIndex: 1, eventIndex: 2}})
      }
    )
);

describe(
  "resolveCloseEdit",
  () =>
    test(
      "basic call",
      () => {
        let state: EventTable.state = EventTable.initialState();
        EventTable.resolveCloseEdit(state)
        |> expect
        |> toEqual({...state, edit: {active: false, listIndex: -1, eventIndex: -1}})
      }
    )
);
