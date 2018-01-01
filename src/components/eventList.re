open Utils;

module FetchEvents = Apollo.Client.Query(QueryConfig);

let component = ReasonReact.statelessComponent("EventList");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <FetchEvents>
      (
        (response) =>
          switch response {
          | Loading => <div> (textEl("loading")) </div>
          | Failed(error) => <div> (textEl(error)) </div>
          | Loaded(_result) => <div> (textEl("worked")) </div>
          }
      )
    </FetchEvents>
};
