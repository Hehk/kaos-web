open Jest;
open Expect;

open Utils;

describe("Utils Module tests", () => {
  test("does textEl give a react text element", () => {
    let text = "test";
    text |> textEl |> expect |> toBe(text |> ReasonReact.stringToElement)
  });
});
