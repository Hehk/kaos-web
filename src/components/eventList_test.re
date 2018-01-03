open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = () => Enzyme.shallow(<EventList />);

describe(
  "EventList Component",
  () => {
    test("component renders", () => setup() |> Enzyme.exists |> expect |> toBe(true));
  });

describe("createEvent", () => {
  test("creates renderable event", () => {
    let input : AllEventsQueryConfig.event = { "name": "hello_world" };
    input |> EventList.createEvent |> Enzyme.shallow |> Enzyme.exists |> expect |> toBe(true)
  });
});
