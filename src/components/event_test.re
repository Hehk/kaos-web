open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~name="", ()) => Enzyme.shallow(<Event name />);

describe(
  "Event Component",
  () => {
    test("component renders", () => setup() |> Enzyme.exists |> expect |> toBe(true));
    test(
      "renders custom name",
      () => {
        let name = "testing";
        setup(~name, ()) |> Enzyme.contains(ReasonReact.stringToElement(name)) |> expect |> toBe(true)
      }
    );
  }
);
