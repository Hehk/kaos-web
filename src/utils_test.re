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
    array |> arrayEl |> expect |> toEqual(ReasonReact.arrayToElement(array))
  });

  test("listEl gives an arrar of react elements", () => {
    let list = List.map(textEl, ["hello", "world", "of", "tests"]);
    list |> listEl |> expect |> toEqual(ReasonReact.arrayToElement(Array.of_list(list)))
  });
});
