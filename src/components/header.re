open Utils;

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div className="dt w-100 mw8 center">
      <div className="pa3"> (textEl("Choala")) </div>
      <div className="dtc v-mid tr pa3">
        <Button style=Button.Simple> <a> (textEl("About")) </a> </Button>
        <Button style=Button.Simple> <a> (textEl("Github")) </a> </Button>
        <Button style=Button.Outline> <a> (textEl("LOG IN")) </a> </Button>
        <Button style=Button.Outline> <a> (textEl("SIGN UP")) </a> </Button>
      </div>
    </div>
};
