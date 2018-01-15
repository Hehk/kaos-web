[%bs.raw {|require('./index.css')|}];

[%bs.raw {|require('tachyons/css/tachyons.css')|}];

[@bs.module "./registerServiceWorker"] external register_service_worker : unit => unit = "default";

ReactDOMRe.renderToElementWithId(<App />, "root");
Utils.getUrl() |> ReasonReact.Router.push;

register_service_worker();
