open Jest;

open Expect;

open Utils;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~style=Button.Simple, ~children=[||], ()) => Enzyme.shallow(<Button
style>(arrayEl(children))</Button>);

describe(
  "Button Component",
  () => {
    test("simple render", () => setup() |> Enzyme.exists |> expect |> toBe(true));
    test(
      "renders with different style",
      () => setup(~style=Button.Outline, ()) |> Enzyme.exists |> expect |> toBe(true)
    );
    test("renders children passed in", () => {
      let child = <div id="children_render_rest"></div>;
      setup(~children=[|child|], ()) |> Enzyme.contains(child) |> expect |> toBe(true)
    })
  }
);
