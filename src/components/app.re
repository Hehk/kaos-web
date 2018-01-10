open Utils;

type state = {path: list(string)};

type action =
  | ChangeRoute(ReasonReact.Router.url);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {path: [""]},
  reducer: (action, _state) =>
    switch action {
    | ChangeRoute(url) => ReasonReact.Update({path: url.path})
    },
  subscriptions: self => [
    Sub(
      () => ReasonReact.Router.watchUrl(url => self.send(ChangeRoute(url))),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: self =>
    <div className="App">
      <Header />
      (
        switch self.state.path {
        | [""] => <EventList />
        | ["login"] => <div> (textEl("login")) </div>
        | ["signup"] => <div> (textEl("signup")) </div>
        | _ => <div> (textEl("un recognised")) </div>
        }
      )
    </div>
};
