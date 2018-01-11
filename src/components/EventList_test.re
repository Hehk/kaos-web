open Jest;

open Utils;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let shallow = Enzyme.shallow;
let setup = (~name="", ()) => Enzyme.shallow(<EventList name />);

describe(
  "EventList Component",
  () => {
    test("component renders", () => setup() |> Enzyme.exists |> expect |> toBe(true));
    test("takes a name and renders it in a header", () => {
      let name = "testing";
      let textElement = textEl(name);
      shallow(<EventList name />) |> Enzyme.contains(textElement) |> expect |> toBe(true);
      });

  });

