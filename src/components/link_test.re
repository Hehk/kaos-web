open Jest;

open Expect;

open Utils;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

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
      "",
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
    )
  }
);
