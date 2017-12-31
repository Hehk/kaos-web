open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = () => Enzyme.shallow(<Header />);

describe("Header Component", () => {
  test("component renders", () => {
    let component = setup();
    component
    |> Enzyme.exists
    |> expect
    |> toBe(true)
  });
});
