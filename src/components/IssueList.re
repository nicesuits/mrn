let issuesData: list(IssueType.issue) = [
  {
    id: 1,
    status: "Open",
    owner: "Ravan",
    created: "2016-08-15",
    effort: 5,
    completedDate: "undefined",
    title: "Error in console when clicking Add",
  },
  {
    id: 2,
    status: "Assigned",
    owner: "Eddie",
    created: "2016-08-16",
    effort: 14,
    completedDate: "2016-08-30",
    title: "Missing bottom border on panel",
  },
];

type state = {issues: list(IssueType.issue)};
type action =
  | InitialLoad(list(IssueType.issue))
  | AddIssue(IssueType.issue);

let newIssue = text => {
  let newID =
    issuesData.length
    + 1({
        id: newID,
        status: "Open",
        owner: text.owner,
        created: Js.Date.make(),
        effort: 5,
        completedDate: "",
        title: text.title,
      });
  ();
};
let valueFromEvent = (e): string =>
  {
    e |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj;
  }##value;
let component = ReasonReact.reducerComponent("IssueList");

let make = _children => {
  ...component,
  initialState: () => {issues: []},
  reducer: action =>
    switch (action) {
    | InitialLoad(passedIssues) => (
        state => ReasonReact.Update({...state, issues: passedIssues})
      )
    | AddIssue(text) => ReasonReact.Update({})
    },
  didMount: self => {
    self.send(InitialLoad(issuesData));
  },
  render: self => {
    let {issues} = self.state;
    <div>
      <h1> {ReasonReact.string("Issue Tracker")} </h1>
      <IssueFilter />
      <hr />
      <IssueTable issues />
      <hr />
      <IssueAdd />
    </div>;
  },
};