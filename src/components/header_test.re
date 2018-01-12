open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = () => Enzyme.shallow(<Header />);

describe(
  "Header Component",
  () => {
    test(
      "component renders",
      () => {
        let component = setup();
        component |> Enzyme.exists |> expect |> toBe(true)
      }
    );
    test(
      "renders the simple links",
      () => {
        let text = "About";
        Enzyme.shallow(<Header simpleLinks=[{path: "/about", content: text}: Header.link] />) |>
        Enzyme.html
        |> expect
        |> toContainString(text)
      }
    );
    test(
      "renders the button links",
      () => {
        let text = "About";
        Enzyme.shallow(<Header buttonLinks=[{path: "/about", content: text}: Header.link] />) |>
        Enzyme.html
        |> expect
        |> toContainString(text)
      }
    )


  }
);
