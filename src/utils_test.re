open Jest;
open Expect;

open Utils;

describe("Utils Module tests", () => {
  test("does textEl give a react text element", () => {
    let text = "test";
    text |> textEl |> expect |> toBe(text |> ReasonReact.stringToElement)
  });

  test("arrayEl gives an array of react elements", () => {
    let array = Array.map(textEl, [|"hello", "world", "of", "tests"|]);
    array |> arrayEl |> expect |> toBe(ReasonReact.arrayToElement(array))
  });
});
