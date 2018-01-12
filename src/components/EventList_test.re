open Jest;

open Utils;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let shallow = Enzyme.shallow;
let setup = (~name="", ~events=[], ()) => Enzyme.shallow(<EventList events name />);

describe(
  "EventList Component",
  () => {
    test("component renders", () => setup() |> Enzyme.exists |> expect |> toBe(true));
    test("takes a name and renders it in a header", () => {
      let name = "testing";
      let textElement = textEl(name);
      shallow(<EventList name />) |> Enzyme.contains(textElement) |> expect |> toBe(true);
      });
    test(
      "renders a list of events",
      () => {
        let name = "crazy name";
        let l : list(Event.t) = [{ name: name }];
        setup(~events=l, ()) |> Enzyme.html |> expect |> toContainString(name)
      });

  });

