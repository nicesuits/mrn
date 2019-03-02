type formState = {
  owner: string,
  title: string,
};

type state = {issue: IssueType.issue};
type action =
  | InputIssue(IssueType.issue)
  | Submit;

let component = ReasonReact.reducerComponent("IssueAdd");

let make = _children => {
  let handleSubmit = state => {
    // let newID: int = List.length(state.issue);
    let newID: int = 1;
    let newIssue: IssueType.issue = {
      id: newID,
      status: "Open",
      owner: state.issue.owner,
      created: Js.Date.toDateString(Js.Date.make()),
      effort: 5,
      completedDate: "",
      title: state.issue.title,
    };
    let newList = [newIssue, ...state.issues];
    ReasonReact.Update({issues: newList});
  };
  {
    ...component,
    initialState: () => {issues: []},
    reducer: action =>
      switch (action) {
      | Submit => (state => handleSubmit(state))
      },
    render: _self =>
      <div className="form">
        <input type_="text" name="owner" placeholder="Owner" />
        <input type_="text" name="title" placeholder="Title" />
        <button> {ReasonReact.string("Add")} </button>
      </div>,
  };
};