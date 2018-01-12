open Jest;

open Expect;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = () => Enzyme.shallow(<App />);

let message = (app) => app |> Enzyme.find("h2") |> Enzyme.first;

describe(
  "App Component",
  () =>
    test(
      "component renders",
      (_) => {
        let component = setup();
        component |> Enzyme.exists |> expect |> toBe(true)
      }
    )
);

describe(
  "mapPathToRoute",
  () => {
    let mapUrlToRoute = App.mapUrlToRoute;
    let mapPathToUrl = (path) : ReasonReact.Router.url => {path, search: "", hash: ""};
    test(
      "invalid routes gives home page",
      () => ["invalid", "url", "bad"] |> mapPathToUrl |> mapUrlToRoute |> expect |> toBe(App.Home)
    );
    test(
      "empty route gives home",
      () => [] |> mapPathToUrl |> mapUrlToRoute |> expect |> toBe(App.Home)
    );
    test(
      "/login gives the login route",
      () => ["login"] |> mapPathToUrl |> mapUrlToRoute |> expect |> toBe(App.Login)
    );
    test(
      "/signup gives the signup route",
      () => ["signup"] |> mapPathToUrl |> mapUrlToRoute |> expect |> toBe(App.SignUp)
      );
  }
);

/* Once a new state is added make sure ChangeRoute only effects route */
describe(
  "reducer",
  () =>
    test(
      "ChangeRoute changes route",
      () => {
        let action = App.ChangeRoute({path: [], search: "", hash: ""});
        App.reducer(action, {route: Login}: App.state)
        |> expect
        |> toEqual(ReasonReact.Update({route: App.Home}: App.state));
      }
    )
);
