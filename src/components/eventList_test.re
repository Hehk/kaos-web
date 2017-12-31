open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~events=[||], ()) => Enzyme.shallow(<EventList events />);

describe(
  "EventList Component",
  () => {
    test("component renders", () => setup() |> Enzyme.exists |> expect |> toBe(true));
  });
