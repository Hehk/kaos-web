[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

let query = [@bs] gql({|
  query {
    allEvents {
      name
    }
  }
|});

type event = {. "name": string };
type data = {. "allEvents": array(event)};
type response = data;

type variables = {. "id": string };

