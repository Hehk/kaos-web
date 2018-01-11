open Jest;

open Expect;

open Utils;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let shallow = Enzyme.shallow;
let setup = (~style=Link.Simple, ~href="", ~children=[||], ()) =>
  Enzyme.shallow(<Link style href> (arrayEl(children)) </Link>);

describe(
  "Link Component",
  () => {
    test("simple render", () => setup() |> Enzyme.exists |> expect |> toBe(true));
    test(
      "renders with different style",
      () => setup(~style=Link.InheritStyle, ()) |> Enzyme.exists |> expect |> toBe(true)
    );
    test(
      "handle passing in a child component",
      () => {
        let child = textEl("test");
        setup(~children=[|child|], ()) |> Enzyme.contains(child) |> expect |> toBe(true)
      }
    );
    test(
      "add custom href",
      () => {
        let href = "/test";
        setup(~href, ()) |> Enzyme.find("a[href='/test']") |> Enzyme.exists |> expect |> toBe(true)
      }
    );
    test(
      "add custom className",
      () => {
        let link = shallow(<Link className="testing1234" href="" />);
        link |> Enzyme.find(".testing1234") |> Enzyme.exists |> expect |> toBe(true)
      }
    )
  }
);
