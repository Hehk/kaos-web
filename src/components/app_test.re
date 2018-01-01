open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = () => Enzyme.shallow(<App />);

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
  }
);
