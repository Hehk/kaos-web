/* I hate typing this out every time */
let textEl = ReasonReact.stringToElement;
let arrayEl = ReasonReact.arrayToElement;
let listEl = (l) => l |> Array.of_list |> arrayEl;
