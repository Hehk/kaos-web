open Utils;

module FetchEvents = Apollo.Client.Query(AllEventsQueryConfig);

let component = ReasonReact.statelessComponent("EventList");

let createEvent = (event: AllEventsQueryConfig.event) => <Event name=event##name />;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <FetchEvents>
      (
        (response) =>
          switch response {
          | Loading => <div> (textEl("loading")) </div>
          | Failed(error) => <div> (textEl(error)) </div>
          | Loaded(result) => result##allEvents |> Array.map(createEvent) |> arrayEl
          }
      )
    </FetchEvents>
};
