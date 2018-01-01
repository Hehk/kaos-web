open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = () => Enzyme.shallow(<EventList />);

describe(
  "EventList Component",
  () => {
    test("component renders", () => setup() |> Enzyme.exists |> expect |> toBe(true));
  });
