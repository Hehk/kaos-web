/* I hate typing this out every time */
let textEl = ReasonReact.stringToElement;

let arrayEl = ReasonReact.arrayToElement;

let listEl = (l) => l |> Array.of_list |> arrayEl;

[@bs.get] external location : Dom.window => Dom.location = "";

[@bs.get] external url : Dom.location => string = "";

/* gets the current url */
let getUrl = () =>
  switch [%external window] {
  | None => ""
  | Some((window: Dom.window)) => window |> location |> url
  };
