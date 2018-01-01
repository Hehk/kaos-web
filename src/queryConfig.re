[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

let query = [@bs] gql({|
  query getEvents {
    name
  }
|});

type event = {. "name": string };
type data = {. "todos": array(event)};
type response = data;

type variables = {. "id": string };

