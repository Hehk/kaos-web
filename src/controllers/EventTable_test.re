open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let shallow = Enzyme.shallow;

describe("EventTable Component", () => {
 test("Component renders", () => shallow(<EventTable />) |> Enzyme.exists |> expect |> toBe(true)); 
});

describe("EventTable Reducer", () => {
  test("MoveEvent", () => {
    let state : EventTable.state = { eventLists: [] };
    switch (EventTable.reducer(EventTable.MoveEvent, state)) {
      | ReasonReact.Update(newState) => newState |> expect |> toEqual(state)
      | _ => false |> expect |> toBe(true)
    }
  });
});
