open Utils;

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div className="dt w-100 mw8 center">
      <div className="pa4 f2"> (textEl("Kaos")) </div>
      <div className="dtc v-mid tr pa3">
        <Button style=Button.Simple> <Link style=Link.InheritStyle href="/about"> (textEl("About"))
        </Link> </Button>
        <Button style=Button.Simple> <Link style=Link.InheritStyle href="/github"> (textEl("Github"))
        </Link> </Button>
        <Button style=Button.Outline>
          <Link style=Link.InheritStyle href="/login"> (textEl("LOG IN")) </Link>
        </Button>
        <Button style=Button.Outline>
          <Link style=Link.InheritStyle href="/signup"> (textEl("SIGN UP")) </Link>
        </Button>
      </div>
    </div>
};
