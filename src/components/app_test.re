open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~message="Test", ()) => Enzyme.shallow(<App message />);

let message = (app) => app |> Enzyme.find("h2") |> Enzyme.first;

describe(
  "App Component",
  () => {
    test(
      "component renders",
      (_) => {
        let component = setup();
        component |> Enzyme.exists |> expect |> toBe(true)
      }
    );
    test(
      "component renders message",
      (_) => {
        let message = "hello world";
        let component = setup(~message, ());
        let expectedNode = <h2> (ReasonReact.stringToElement(message)) </h2>;
        component |> Enzyme.contains(expectedNode) |> expect |> toBe(true)
      }
    )
  }
);
