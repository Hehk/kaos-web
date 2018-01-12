open Utils;

type link = {
  path: string,
  content: string
};

let component = ReasonReact.statelessComponent("Header");

let make = (~simpleLinks=[], ~buttonLinks=[], _children) => {
  ...component,
  render: (_self) =>
    <div className="dt w-100 mw8 center">
      <div className="pa4 f2">
        <Link style=Link.InheritStyle href="/"> (textEl("Kaos")) </Link>
      </div>
      <div className="dtc v-mid tr pa3">
        (
          simpleLinks
          |> List.map(
               ({path, content}) =>
                 <Button key=("simple-button" ++ content) style=Button.Simple>
                   <Link key=("simple-link" ++ content) style=Link.InheritStyle href=path>
                     (textEl(content))
                   </Link>
                 </Button>
             )
          |> listEl
        )
        (
          buttonLinks
          |> List.map(
               ({path, content}) =>
                 <Button key=("outline-button" ++ content) style=Button.Outline>
                   <Link key=("outline-link" ++ content) style=Link.InheritStyle href=path>
                     (textEl(content))
                   </Link>
                 </Button>
             )
          |> listEl
        )
      </div>
    </div>
};
