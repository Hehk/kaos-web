open Jest;

open Expect;

open Utils;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let shallow = Enzyme.shallow;

let setup = (~style=Button.Simple, ~children=[||], ()) =>
  shallow(<Button style> (arrayEl(children)) </Button>);

describe(
  "Button Component",
  () => {
    test("simple render", () => setup() |> Enzyme.exists |> expect |> toBe(true));
    test(
      "renders with different style",
      () => setup(~style=Button.Outline, ()) |> Enzyme.exists |> expect |> toBe(true)
    );
    test(
      "renders children passed in",
      () => {
        let child = <div id="children_render_rest" />;
        setup(~children=[|child|], ()) |> Enzyme.contains(child) |> expect |> toBe(true)
      }
    );
    test(
      "renders without a style",
      () => {
        let button = shallow(<Button />);
        button |> Enzyme.exists |> expect |> toBe(true)
      }
    );
    test(
      "add custom className",
      () => {
        let button = Enzyme.shallow(<Button className="testing1234" />);
        button |> Enzyme.find(".testing1234") |> Enzyme.exists |> expect |> toBe(true)
      }
    )
  }
);
