open Utils;

type route =
  | Home
  | Login
  | SignUp;

type state = {route};

type action =
  | ChangeRoute(ReasonReact.Router.url);

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | [] => Home
  | ["login"] => Login
  | ["signup"] => SignUp
  | _ => Home
  };

let reducer = (action, _state) =>
    switch action {
    | ChangeRoute(url) => ReasonReact.Update({route: url |> mapUrlToRoute})
    };


let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: Home},
  subscriptions: (self) => [
    Sub(
      () => ReasonReact.Router.watchUrl((url) => self.send(ChangeRoute(url))),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: ({state}) =>
    <div className="App">
      <Header />
      (
        switch state.route {
        | Home => <EventTable />
        | Login => <div> (textEl("login")) </div>
        | SignUp => <div> (textEl("signup")) </div>
        }
      )
    </div>
};
