open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~name="", ~onClick=(() => Js.log("test")), ()) => Enzyme.shallow(<Event name onClick />);

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
    test("handles onClick", () => {
      let clicked = ref(false);
      let onClick = () => clicked := true;
      Enzyme.shallow(<Event name="test" onClick />)
      |> Enzyme.find(".event")
      |> Enzyme.simulate("click");
      clicked^ |> expect |> toBe(true);
    });
  }
);
