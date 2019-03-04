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
  | InitialLoad(list(IssueType.issue));

let valueFromEvent = event => {
  event->ReactEvent.Form.target##value;
};

let component = ReasonReact.reducerComponent("IssueList");

let make = _children => {
  {
    let createIssue = state => {
      let newID: int = List.length(state.issues) + 1;
      let newIssue: IssueType.issue = {
        id: newID,
        status: "Open",
        owner: "owner",
        created: Js.Date.toDateString(Js.Date.make()),
        effort: 5,
        completedDate: "",
        title: "title",
      };
      let newList = [newIssue, ...state.issues];
      ReasonReact.Update({issues: newList});
    };
    ();
  };
  {
    ...component,
    initialState: () => {issues: []},
    reducer: action =>
      switch (action) {
      | InitialLoad(passedIssues) => (
          state => ReasonReact.Update({...state, issues: passedIssues})
        )
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
};