open Utils;

let component = ReasonReact.statelessComponent("EventList");

let make = (~events, _children) => {
  ...component,
    render: (_self) => <div>
        (arrayEl(events))
      </div>
};
